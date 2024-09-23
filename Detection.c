#include <stdio.h>
#include <windows.h>

void printErrorMessage() {
    DWORD errorMessageID = GetLastError(); 

    if (errorMessageID != 0) { 
        LPSTR messageBuffer = NULL;

        size_t size = FormatMessageA(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPSTR)&messageBuffer, 0, NULL
        );

        printf("Error: %s\n", messageBuffer);

        LocalFree(messageBuffer);
    }
}

//scanning the system

void ScanDirectory(const char *dirPath){
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;

    // prepare the search Pattern

    char searchPath[MAX_PATH];
    snprintf(searchPath,sizeof(searchPath), "%s\\*", dirPath);

    //start searching 

    hfind = FindFirstFile(searchPath, &findfileData);
    if (hfind == INVALID_HANDLE_VALUE){
        printf("could not open directory : %s\n");
        return;
    }


}


int main(){

    return 0;

}


/// int main() {
    
    //char currentPath[MAX_PATH];
   // if (GetCurrentDirectoryA(MAX_PATH, currentPath)) {
     //   printf("current working directory: %s\n", currentPath);
   // }
   // else {
   //     printf("failed to get current directory.\n");
   // }

  //  return 0;
//}