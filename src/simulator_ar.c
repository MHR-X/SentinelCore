/*
=========================================================
 SentinelCore – محاكاة سلوك المالوير (تعليمي فقط)
---------------------------------------------------------
- الكود ده لا ينفذ مالوير حقيقي.
- مفيش persistence فعلي.
- مفيش تنفيذ أوامر عن بعد.
- مفيش C2 أو تحكم خارجي.
- محاكاة الشبكة Localhost فقط ومقفولة افتراضيًا.
- الهدف الفهم والكشف، مش الإساءة.
=========================================================
*/

#include <windows.h>
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

/*
---------------------------------------------------------
 مفاتيح الأمان (كلها مقفولة افتراضيًا)
---------------------------------------------------------
أي محاكاة لازم تتفعل يدوي وقت الكومبايل.
مثال:
  cl /D ENABLE_SIM_PERSISTENCE /D ENABLE_SIM_NETWORK simulator_ar.c
---------------------------------------------------------
*/
#if !defined(ENABLE_SIM_PERSISTENCE)
#define ENABLE_SIM_PERSISTENCE 0
#endif

#if !defined(ENABLE_SIM_NETWORK)
#define ENABLE_SIM_NETWORK 0
#endif

// ------------------------------------------------------
// المحاكاة 1: الكتابة في الريجيستري (فكرة الـ Persistence)
// ------------------------------------------------------
void SimulatePersistence(void) {

#if ENABLE_SIM_PERSISTENCE

    // محاكاة تعليمية فقط
    // بنكتب قيمة تجريبية في HKCU (نطاق المستخدم الحالي)
    // مفيش Startup ولا تشغيل ملفات

    HKEY hKey;
    if (RegCreateKeyA(
            HKEY_CURRENT_USER,
            "Software\\SentinelCore\\Simulation",
            &hKey
        ) == ERROR_SUCCESS)
    {
        // مجرد اسم ملف كنص، لا يتم تشغيله
        const char* value = "test.exe";

        // كتابة القيمة في الريجيستري للتجربة فقط
        RegSetValueExA(
            hKey,
            "SimulatedPayload",
            0,
            REG_SZ,
            (const BYTE*)value,
            (DWORD)(strlen(value) + 1)
        );

        RegCloseKey(hKey);
        printf("[SIM] تم تنفيذ محاكاة الريجيستري (HKCU فقط).\n");
    }

#else
    printf("[SIM] محاكاة الـ Persistence مقفولة حاليًا.\n");
#endif
}

// ------------------------------------------------------
// المحاكاة 2: اتصال شبكة محلي (مفهومي فقط)
// ------------------------------------------------------
void SimulateNetworkCall(void) {

#if ENABLE_SIM_NETWORK

    // محاكاة تعليمية فقط
    // الاتصال يتم على 127.0.0.1 (Localhost)
    // لا يتم إرسال أو استقبال بيانات
    // ده مش Reverse Shell ومش قناة تحكم

    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("[SIM] فشل تهيئة Winsock.\n");
        return;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        WSACleanup();
        printf("[SIM] فشل إنشاء الـ Socket.\n");
        return;
    }

    struct sockaddr_in addr;
    ZeroMemory(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4444);                 // بورت ثابت للتجربة
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost فقط

    if (connect(s, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
        printf("[SIM] تم الاتصال بخدمة محلية على الجهاز.\n");
    } else {
        printf("[SIM] لا توجد خدمة محلية تعمل (وده المتوقع غالبًا).\n");
    }

    closesocket(s);
    WSACleanup();

#else
    printf("[SIM] محاكاة الاتصال الشبكي مقفولة حاليًا.\n");
#endif
}

/*
---------------------------------------------------------
 الدالة الرئيسية
---------------------------------------------------------
لا يوجد تنفيذ تلقائي.
أي محاكاة لازم تتنادى يدوي للتجربة التعليمية.
---------------------------------------------------------
*/
int main(void) {
    printf("[INFO] SentinelCore – إطار محاكاة تعليمي\n");
    printf("[INFO] جميع المحاكاة مقفولة افتراضيًا.\n");

    // فك التعليق فقط في بيئة اختبار تعليمية:
    // SimulatePersistence();
    // SimulateNetworkCall();

    return 0;
}
