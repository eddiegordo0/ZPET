//
// Created by 010010 on 28/05/2020.
//

#include "scanhandler.h"
#include "res.h"
#include "processor.h"
#include <stdio.h>

int scanhandle(int opt){
    cleanmenu(0,"");
    if(ios_fetch_access("127.0.0.1","2222")==0){
        switch(opt){
            case 2:
                printf("Quick - B100\n");
                macos_run_comm("rm report.html 2>/dev/null");
                macos_run_comm("echo '\<html\> \<head\> \<style\> body \{font-family: arial\;\} \<\/style\> \<\/head\> \<body\>\<h1\>ZPET REPORT - DuffyAPP_IT - Quick Scan - B100\</h1\>' \>\> report.html");
                //Here we define which processors to use for each struct defining each module.
                plistproc(wifi());
                sqliteproc(accounts());
                plistproc(bsn());
                plistproc(vpnd());
                custproc(mailextract());
                sqliteproc(wifiloc());
                printf("Report available at -> %s/report.html\n", strtok(macos_run_comm("pwd"),"\n"));
                break;
            case 3:
                printf("Extended - B100\n");
                macos_run_comm("rm report.html 2>/dev/null");
                macos_run_comm("echo '\<html\> \<head\> \<style\> body \{font-family: arial\;\} \<\/style\> \<\/head\> \<body\>\<h1\>ZPET REPORT - DuffyAPP_IT - Extended - B100\</h1\>' \>\> report.html");
                plistproc(wifi());
                sqliteproc(accounts());
                sqliteproc(PCInfo());
                plistproc(bsn());
                sqliteproc(PCInfo());
                sqliteproc(callhist());
                plistproc(vpnd());
                sqliteproc(appids());
                jsonproc(wallet());
                custproc(wapp());
                custproc(mailvip());
                printf("Report available at -> %s/report.html\n", strtok(macos_run_comm("pwd"),"\n"));
                break;
            case 4:
                printf("Custom Module\n");
                break;
            default:
                printf("Invalid Value -> ScanHandler\n");
                exit(1);
        }
    } else{
        printf("iDevice Connection Issue...\nCheck Setup Instructions..\n");
        exit(1);
    }
    return 1;
}
