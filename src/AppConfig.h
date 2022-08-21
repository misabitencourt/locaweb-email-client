


class AppConfig {

    private:        
        std::map<int, std::string> configs;

    public:
        static const int ACCESS_TOKEN = 1;
        static const int EMAIL_FROM = 2;

        void load() 
        {
            std::fstream configFileStream("./config.cfg");
            std::string lineBuffer;
            int line = 1;
            if (configFileStream.is_open())
            {
                while (getline(configFileStream, lineBuffer))                
                {
                    int lineLength = lineBuffer.length();
                    if (!lineLength) 
                    {
                        continue;
                    }
                    int separatorIndex = lineBuffer.find('=');
                    if (separatorIndex > lineLength) 
                    {
                        printf("Config error on line %i", line);
                        continue;
                    }
                    std::string configKey = lineBuffer.substr(0, separatorIndex);
                    std::string configValue = lineBuffer.substr(separatorIndex, lineLength-1);                    
                    if (configKey.find('ACCESS_TOKEN') < lineLength)
                    {
                        configs[ACCESS_TOKEN] = configValue;
                        continue;
                    }
                    if (configKey.find('EMAIL_FROM') < lineLength)
                    {
                        configs[ACCESS_TOKEN] = configValue;
                        continue;
                    }
                    line++;
                }
            }
            else
            {
                printf("The config file doesnt exists\n");
                exit(1);
            }
        }

        std::string getConfig(int config) 
        {
            return configs[config];
        }
};
