# SentinelCore
Malware Behavior Simulation for Analysis & Educational Development

---

## Overview

SentinelCore is an educational cybersecurity project focused on **understanding malware behavior by simulating it safely**.  
Instead of using real malware or dangerous tools, this project demonstrates *how such behaviors are designed* and *how they appear to the operating system*, allowing learners and researchers to analyze them without risk.

The project is built to support both:
- **Malware Analysis**
- **Malware Development (Educational & Controlled)**

No real malicious activity is performed. Everything is explicit, transparent, and disabled by default.

---

## Why SentinelCore Exists

Most people study malware by:
- Reading theory only, or
- Running unknown samples in sandboxes

SentinelCore takes a different approach:
You **build and read the logic yourself**.

By understanding how malware-like behaviors are written at code level, you gain:
- Better analysis skills
- Stronger defensive thinking
- Clear insight into detection logic

---

## What the Code Demonstrates

SentinelCore simulates common malware concepts in a **safe and limited form**.

### 1. Persistence (Simulation)

The code demonstrates how persistence *conceptually* works by:
- Writing a harmless test value
- Using `HKEY_CURRENT_USER` only
- Avoiding startup locations
- Never executing or loading anything

This allows the reader to understand:
- Why registry-based persistence exists
- How it is typically implemented
- How security tools monitor such behavior

---

### 2. Network Behavior (Simulation)

The network simulation demonstrates:
- Socket creation
- Connection logic
- Typical malware network flow

Key limitations:
- Connection is **localhost only (127.0.0.1)**
- No data is sent
- No data is received
- No remote control
- No command execution

The purpose is to show **structure and intent**, not exploitation.

---

## Safety by Design

SentinelCore is intentionally built with safety controls:

- All simulations are **disabled by default**
- Behavior must be explicitly enabled at compile time
- No obfuscation
- No hidden logic
- No persistence outside user scope
- No real attack surface

This makes the project suitable for:
- Learning
- Teaching
- Code review
- Malware analysis practice

---

## Example Code Concept

```c
#if ENABLE_SIM_PERSISTENCE
HKEY hKey;
if (RegCreateKeyA(
        HKEY_CURRENT_USER,
        "Software\\SentinelCore\\Simulation",
        &hKey
    ) == ERROR_SUCCESS)
{
    const char* value = "test.exe";

    RegSetValueExA(
        hKey,
        "SimulatedPayload",
        0,
        REG_SZ,
        (const BYTE*)value,
        (DWORD)(strlen(value) + 1)
    );

    RegCloseKey(hKey);
    printf("[SIM] Registry simulation completed.\n");
}
#endif
````

This snippet demonstrates:

* Registry interaction
* Safe persistence modeling
* Clear detection points
* Transparent logic

Nothing is executed. Nothing is hidden.

---

## Project Structure

```
SentinelCore/
│
├── src/
│   ├── simulator.c        // English comments
│   ├── simulator_ar.c     // Arabic comments
│
├── README.md              // Project landing page
├── README_AR.md           // Full Arabic documentation
```

---

## Who This Project Is For

* Cybersecurity beginners
* Malware analysis students
* Security researchers
* Developers curious about malware internals
* Anyone who wants to understand *how malware logic works* without using real malware

---

## About the Author

My name is **Mohamed Abdelrahman**.

I am a cybersecurity enthusiast focused on:

* Malware behavior analysis
* Focus on developing malware
* Focus on teaching how to develop malware securely
* Focus on teaching hacking in secure environments
* Understanding attacker logic
* Building strong defensive knowledge

SentinelCore is part of my learning journey, created to:

* Study malware logic responsibly
* Share knowledge clearly
* Encourage ethical learning in cybersecurity
