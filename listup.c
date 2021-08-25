#include <sys/types.h> 
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*);

/* ���丮 ������ �ڼ��� ����Ʈ�Ѵ�. */
int main(int argc, char **argv) 
{
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ+1];

    if (argc == 1) 
        dir = ".";
    else dir = argv[1];

    if ((dp = opendir(dir)) == NULL)  // ���丮 ���� 
        perror(dir);

    while ((d = readdir(dp)) != NULL) {	// ���丮 ���� �� ���Ͽ� ���� 
        sprintf(path, "%s/%s", dir, d->d_name); // ���� ��θ� ����� 
        if (lstat(path, &st) < 0) 	// ���� ���� ���� ��������  
            perror(path);
        else 
            printStat(path, d->d_name, &st);  // ���� ���� ���
    }

    closedir(dp);
    exit(0);
}

/* ���� ���� ������ ��� */
void printStat(char *pathname, char *file, struct stat *st) {

    printf("%5d ", st->st_blocks);
    printf("%c%s ", type(st->st_mode), perm(st->st_mode));
    printf("%3d ", st->st_nlink);
    printf("%s %s ", getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
    printf("%9d ", st->st_size);
    printf("%.12s ", ctime(&st->st_mtime)+4);
    printf("%s\n", file);
}

/* ���� Ÿ���� ���� */
char type(mode_t mode) {

    if (S_ISREG(mode)) 
        return('-');
    if (S_ISDIR(mode)) 
        return('d');
    if (S_ISCHR(mode)) 
        return('c');
    if (S_ISBLK(mode)) 
        return('b');
    if (S_ISLNK(mode)) 
        return('l');
    if (S_ISFIFO(mode)) 
        return('p');
    if (S_ISSOCK(mode)) 
        return('s');
}

/* ���� �㰡���� ���� */
char* perm(mode_t mode) {
    int i;
    static char perms[10]; 

    strcpy(perms, "????");

    for (i=0; i < 3; i++) {
        if (mode & (S_IREAD >> i*3)) 
            perms[i*3] = 'r';
        if (mode & (S_IWRITE >> i*3)) 
            perms[i*3+1] = 'w';
        if (mode & (S_IEXEC >> i*3)) 
            perms[i*3+2] = 'x';
    }
   return(perms);
}
