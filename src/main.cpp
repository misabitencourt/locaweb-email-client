#include <stdio.h>
#include "./lib/httplib.h"
#include "./Attachement.h"
#include "./AppConfig.h"
#include "./MailFileReader.h"

int main()
{
    printf("TODO\n");

    AppConfig config;
    config.load();

    MailFileReader emailFile;
    emailFile.load();
}