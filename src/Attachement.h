

class Attachement {

    public:
        std::string fileName;
        std::string base64;
        std::string mimeType;


        void base64Encode()
        {
            std::fstream attachementFile(fileName.c_str());
            if (attachementFile.is_open())
            {
                attachementFile.seekg(0, attachementFile.end);
                unsigned int length = attachementFile.tellg();
                attachementFile.seekg(0, attachementFile.beg);
                char * buffer = new char[length];
                attachementFile.read(buffer, length);
                attachementFile.close();
                base64 = base64_encode((unsigned char const*)buffer, length, false);
                delete []buffer;
            }
            else
            {
                printf("Failed to open the file %s", fileName.c_str());
                exit(1);
            }
        }

};
