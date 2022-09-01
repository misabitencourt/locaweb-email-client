#include <stdio.h>
#include "./lib/base64.h"
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "./lib/httplib.h"
#include "./Attachement.h"
#include "./AppConfig.h"
#include "./MailFileReader.h"

int main(int argc, char **argv)
{
    AppConfig config;    
    config.load(argc, argv);    

    MailFileReader emailFile;
    emailFile.load(config);
    emailFile.send();
}