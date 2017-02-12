//
// Created by abondar on 2/11/17.
//

#ifndef SOMEC_FILE_IOS_H
#define SOMEC_FILE_IOS_H


void openFile(char *fname);
void createFile(char *fname);
void readFile(char *fname);
void writeFile(char *fname);
void fileSync(char *fname);
void fileSeek(char *fname);
void truncateFile(char *fname,int newLen);

#endif //SOMEC_FILE_IOS_H


