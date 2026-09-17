# Mutual Exclusion Using Semaphore and Monitor

## Use Case

Robot Charging System

## Objective

To demonstrate mutual exclusion using semaphore and monitor concepts in a robot charging system where multiple robots share a charging station.

## Problem

Multiple robots may try to access the same charging station simultaneously.

Since the charging station is a shared resource, mutual exclusion is required to ensure that only one robot accesses the charging station at a time.

## Mutual Exclusion Using Semaphore and Monitor

### Semaphore

A semaphore is a synchronization mechanism used to control access to a shared resource.

In this system, a binary semaphore is used to ensure that only one robot can charge at a time.

- `sem_wait()` is used to acquire the charging station.
- The robot performs the charging operation.
- `sem_post()` releases the charging station for the next robot.

### Monitor

A monitor is a high-level synchronization mechanism that provides mutual exclusion for shared resources.

In this system, the monitor controls access to the charging station and ensures that only one robot enters the critical section at a time.

### Robot Charging Flow

1. Multiple robot threads request access to the charging station.
2. The synchronization mechanism checks whether the station is available.
3. Only one robot is allowed to enter the critical section.
4. The selected robot starts charging.
5. After charging is completed, the robot releases the resource.
6. The next waiting robot can access the charging station.

## Semaphore vs Monitor

| Feature | Semaphore | Monitor |
|---|---|---|
| Type | Synchronization primitive | High-level synchronization mechanism |
| Mutual Exclusion | Controlled using semaphore | Provided by monitor |
| Access Control | `sem_wait()` and `sem_post()` | Monitor procedures |
| Shared Resource | Charging station | Charging station |
| Programming Level | Lower-level | Higher-level |

## Implementation

The robot charging system demonstrates mutual exclusion using semaphore and monitor concepts.

The programs are implemented in C and executed in Ubuntu using POSIX threads.

### Files

- `semph.c` - Semaphore-based mutual exclusion
- `monitor.c` - Monitor-based mutual exclusion

## Compilation

### Semaphore and Monitor

```bash
gcc semph.c -o semaph -pthread
./semaph

gcc monitor.c -o monitor -pthread
./monitor
