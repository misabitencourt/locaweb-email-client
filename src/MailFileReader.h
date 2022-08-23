
class MailFileReader {

    private:        
        std::list<Attachement> files;
        std::string from;
        std::string to;
        std::string subject;
        std::string message;
        bool loaded = false;
        static const int READING_TO = 1;
        static const int READING_SUBJECT = 2;
        static const int READING_ATTACHEMENTS = 3;
        static const int READING_MESSAGE = 4;
        AppConfig config;

    public:
        void load(AppConfig _config) 
        {
            config = _config;
            from = config.getConfig(EMAIL_FROM);
            std::fstream emailFile("./email.txt");
            if (emailFile.is_open())
            {
                std::string lineBuffer;
                int state = READING_TO;
                int line = 0;
                while (getline(emailFile, lineBuffer))
                {
                    line++;
                    int lineLength = lineBuffer.length();
                    if (!lineLength)
                    {
                        continue;
                    }
                    if (!lineBuffer.find("----"))
                    {
                        state++;
                        continue;
                    }
                    if (state == READING_TO)
                    {
                        to = lineBuffer.substr(0, lineLength);
                        continue;
                    }
                    if (state == READING_SUBJECT)
                    {
                        subject = lineBuffer.substr(0, lineLength);
                        continue;
                    }
                    if (state == READING_ATTACHEMENTS)
                    {
                        int pipeIndex = lineBuffer.find("|");
                        if (pipeIndex > lineLength)
                        {
                            printf("Attachment without mimetype on email line %i", line);
                            exit(1);
                        }
                        Attachement attachment;
                        attachment.fileName = lineBuffer.substr(0, pipeIndex);
                        attachment.mimeType = lineBuffer.substr(pipeIndex, lineLength);
                        attachment.base64Encode();
                        files.push_back(attachment);
                        continue;
                    }
                    if (state == READING_MESSAGE)
                    {
                        message += lineBuffer;
                    }
                }
                emailFile.close();
                loaded = true;
            }
            else
            {
                printf("Email file is not loaded\n");
            }
        }

        void send()
        {
            if (loaded == false)
            {
                printf("Email not loaded\n");
                exit(1);
            }
            std::string jsonBody = "{\"subject\":\""+ subject +"\",\"from\": \""+ from +"\",\"to\":\""+ to +"\",";
            jsonBody += "\"headers\":{\"Content-Type\":\"multipart/mixed; boundary=\\\"00001\\\"\",\"MIME-Version\": \"1.0\"},";
            jsonBody += "\"body\": \"--00001\\r\\nContent-Type: text/html\\r\\n\\r\\n<!DOCTYPE html> "+ message +"\\r\\n--00001";
            jsonBody += "\\r\\n--00001--\"}";
            printf("json: %s", jsonBody.c_str());

        }

};
