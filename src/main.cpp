#include <stdio.h>
#include "./lib/base64.h"
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "./lib/httplib.h"
#include "./Attachement.h"
#include "./AppConfig.h"
#include "./MailFileReader.h"

int main()
{
    AppConfig config;
    config.load();

    MailFileReader emailFile;
    emailFile.load(config);
    emailFile.send();
}