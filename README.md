# xv6 Lottery Scheduler

A modified version of the xv6 operating system implementing a lottery scheduler to provide proportional-share CPU scheduling using tickets.

### Overview

This project replaces xv6’s default round-robin scheduler with a lottery-based scheduler, where runnable processes are assigned tickets and CPU time is allocated probabilistically based on ticket ownership. The implementation demonstrates kernel-level scheduling, synchronization, and fairness guarantees.

### Key Features

🎟️ Ticket-based scheduling for proportional CPU allocation

⚖️ Fairness ensured through probabilistic selection

🧮 Tracks and sums tickets across all runnable processes

🧵 Supports multiple concurrent processes with predictable CPU shares

🧪 Verified via multi-process stress tests and controlled experiments

### Implementation Details

Modified the process scheduler in proc.c

Added per-process ticket accounting

Implemented random ticket selection to choose the next runnable process

Ensured correctness under concurrent workloads

Preserved xv6 kernel invariants and process lifecycle semantics

### Testing & Validation

Ran multiple CPU-bound processes with different ticket counts

Observed proportional CPU usage over time

Verified absence of starvation and scheduling anomalies

### Build & Run
make clean
make qemu

### Files Modified

proc.c – core scheduler logic

proc.h – process structure updates


### Learning Outcomes

Deep understanding of OS scheduling algorithms

Practical experience modifying a Unix-like kernel

Insights into fairness, concurrency, and low-level systems design

# NOTE

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

# ACKNOWLEDGMENTS

xv6 is inspired by John Lions's Commentary on UNIX 6th Edition (Peer
to Peer Communications; ISBN: 1-57398-013-7; 1st edition (June 14,
2000)). See also http://pdos.csail.mit.edu/6.828/2007/v6.html, which
provides pointers to on-line resources for v6.

xv6 borrows code from the following sources:
    JOS (asm.h, elf.h, mmu.h, bootasm.S, ide.c, console.c, and others)
    Plan 9 (bootother.S, mp.h, mp.c, lapic.c)
    FreeBSD (ioapic.c)
    NetBSD (console.c)

The following people made contributions:
    Russ Cox (context switching, locking)
    Cliff Frey (MP)
    Xiao Yu (MP)
    Nickolai Zeldovich
    Austin Clements

In addition, we are grateful for the patches contributed by Greg
Price, Yandong Mao, and Hitoshi Mitake.

The code in the files that constitute xv6 is
Copyright 2006-2007 Frans Kaashoek, Robert Morris, and Russ Cox.

# ERROR REPORTS

If you spot errors or have suggestions for improvement, please send
email to Frans Kaashoek and Robert Morris (kaashoek,rtm@csail.mit.edu). 


