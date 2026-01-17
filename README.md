# SentinelCore

## Introduction

SentinelCore is a purely educational project aimed at simulating some common malware behaviors in a safe, limited, and non-harmful way. The main purpose of this project is understanding, analysis, and learning: how such behaviors work from a theoretical perspective, and how they can be detected or analyzed by security systems and researchers.

This project is not intended to harm any system, does not provide real offensive tools, and must not be used outside a personal, authorized testing environment.

---

## Project Objectives

* Understand the core concepts behind common malware behaviors.
* Learn how to write code that simulates these behaviors without actually executing them.
* Help beginners in cybersecurity bridge the gap between theory and practical implementation.
* Train security researchers to read code and analyze the potential intent behind it.

---

## What Does SentinelCore Do?

The project only simulates limited educational behaviors, such as:

* Simulating the concept of persistence using the Windows Registry without creating autorun entries or any real impact.
* Simulating a local network connection (localhost only) without sending or receiving data.

All of these behaviors are:

* Disabled by default.
* Only activated manually at compile time.
* Non-dangerous to the system.

---

## What Does the Project NOT Do?

SentinelCore does NOT:

* Create real malware.
* Establish Command-and-Control (C2) connections.
* Execute remote commands.
* Spread across a network.
* Install itself automatically on the system.
* Bypass security protections.

All code in this project remains strictly within the scope of educational simulation.

---

## Warnings and Responsible Use

* Use this project only on your personal device or in an isolated testing environment.
* Do not run or modify the code on systems you do not explicitly own or have permission to test.
* Any use outside the educational or research scope is solely the user's responsibility.
* This project is intended for learning, not for any illegal activity.

---

## Requirements

* Windows operating system.
* A C compiler that supports the Windows API, such as MSVC.
* Basic knowledge of the C programming language.
* Interest in cybersecurity and malware analysis.

---

## Build Instructions (Compile)

By default, all simulations are disabled.

To compile without enabling any simulation:

