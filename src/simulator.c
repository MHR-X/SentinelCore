/*
=========================================================
 SentinelCore – Malware Behavior Simulation (EDUCATIONAL)
---------------------------------------------------------
- This code DOES NOT implement real malware.
- No real persistence.
- No remote command execution.
- No C2 infrastructure.
- Network simulation is LOCALHOST ONLY and DISABLED by default.
- Intended for learning how such behaviors are DETECTED, not abused.
=========================================================
*/

#include <windows.h>
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

/*
---------------------------------------------------------
 SAFETY SWITCHES (ALL DISABLED BY DEFAULT)
---------------------------------------------------------
 To enable a simulation, you must explicitly define it
 at compile time. Example:
   cl /D ENABLE_SIM_PERSISTENCE /D ENABLE_SIM_NETWORK demo.c
---------------------------------------------------------
*/
#if !defined(ENABLE_SIM_PERSISTENCE)
#define ENABLE_SIM_PERSISTENCE 0
#endif

#if !defined(ENABLE_SIM_NETWORK)
#define ENABLE_SIM_NETWORK 0
#endif

// ------------------------------------------------------
// SIMULATION 1: Registry Write (Persistence Concept)
// ------------------------------------------------------
void SimulatePersistence(void) {

#if ENABLE_SIM_PERSISTENCE

    // EDUCATIONAL SIMULATION ONLY
    // Writes a harmless test value under HKCU (user scope)
    // This does NOT create startup persistence.

    HKEY hKey;
    if (RegCreateKeyA(
            HKEY_CURRENT_USER,
            "Software\\SentinelCore\\Simulation",
            &hKey
        ) == ERROR_SUCCESS)
    {
        const char* value = "test.exe"; // Not executed, name only

        RegSetValueExA(
            hKey,
            "SimulatedPayload",
            0,
            REG_SZ,
            (const BYTE*)value,
            (DWORD)(strlen(value) + 1)
        );

        RegCloseKey(hKey);
        printf("[SIM] Registry simulation completed (HKCU only).\n");
    }

#else
    printf("[SIM] Persistence simulation is DISABLED.\n");
#endif
}

// ------------------------------------------------------
// SIMULATION 2: Local Network Connection (Conceptual)
// ------------------------------------------------------
void SimulateNetworkCall(void) {

#if ENABLE_SIM_NETWORK

    // EDUCATIONAL SIMULATION ONLY
    // Connects to 127.0.0.1 (localhost) for demonstration.
    // No data is sent or received.
    // This is NOT a reverse shell and NOT a C2 channel.

    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("[SIM] WSAStartup failed.\n");
        return;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        WSACleanup();
        printf("[SIM] Socket creation failed.\n");
        return;
    }

    struct sockaddr_in addr;
    ZeroMemory(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4444);              // Fixed demo port
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // LOCALHOST ONLY

    if (connect(s, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
        printf("[SIM] Connected to LOCALHOST demo service.\n");
    } else {
        printf("[SIM] No local service listening (expected in most cases).\n");
    }

    closesocket(s);
    WSACleanup();

#else
    printf("[SIM] Network simulation is DISABLED.\n");
#endif
}

/*
---------------------------------------------------------
 MAIN
---------------------------------------------------------
 Nothing runs automatically.
 You must explicitly call simulations for learning.
---------------------------------------------------------
*/
int main(void) {
    printf("[INFO] SentinelCore Simulation Framework\n");
    printf("[INFO] All simulations are disabled by default.\n");

    // Uncomment ONLY for controlled educational testing:
    // SimulatePersistence();
    // SimulateNetworkCall();

    return 0;
}
