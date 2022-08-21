
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
        static const int READING_END = 5;

    public:
        void load() 
        {
            std::fstream emailFile("./email.txt");
            if (emailFile.is_open())
            {
                std::string lineBuffer;
                while (getline(emailFile, lineBuffer))
                {
                    int lineLength = lineBuffer.length();
                    if (!lineLength)
                    {
                        continue;
                    }
                    // TODO to read
                }
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
        }

};
