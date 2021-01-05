# Coroutines

## References
* [CppCoro - A coroutine library for C++](https://github.com/lewissbaker/cppcoro)
* [c++20 Compiler Explorer](https://godbolt.org/z/jTS9BR)



## Introduce
Coroutines are functions that can suspend and resume their execution while keeping their state. 

With the new keywords **co_await** and **co_yield**, C++20 extends the execution of C++ functions with two new concepts.
* Thanks to **co_await** expression expression, it is possible to suspend and resume the execution of the an expression. *If you use co_await expression in a function func, the call auto getResult = func() does not block if the result of the function is not available*. Instead of resource-consuming blocking, you have resource-friendly waiting.
* **co_yield** *expression expression allows it to write a generator function*. The generator function returns a new value each time. A generator function is a kind of data stream from which you can pick values. The data stream can be infinite. Consequentially, we are in the center of lazy evaluation.


## The first question you may have is: When should I use coroutines?

### Typical Use-Cases
Coroutines are the usual way to write **event-driven applications**. The event-driven application can be simulations, games, servers, user interfaces, or even algorithms. For example, I wrote a few years ago a simulator for a defibrillator in Python. This simulator helped us, in particular, to make clinical usability studies. A defibrillator is an event-driven application, and I implemented it, consequentially, based on the event-driven Python framework twisted. 

Coroutines are also typically used for **cooperative multitasking**. The key to cooperative multitasking is that each task takes as much time as it needs. Cooperative multitasking stands in contrast to preemptive multitasking, for which we have a scheduler that decides how long each task gets the CPU. Cooperative multitasking makes concurrency often easier because a concurrent job can not be interrupted in a critical region. *If you are still puzzled with the terms cooperative and preemptive, I found an excellent overview and read here: Cooperative vs. Preemptive: a quest to maximize concurrency power.*

### Underlying Ideas

Coroutines in C++20 are **asymmetric, first-class, and stackless**.

The workflow of an asymmetric coroutine goes back to the caller. 
First-class coroutines behave like data. Behaving like data means you can use them as an argument to or return value from a function, or store them in a variable.
A stackless coroutine enables it to suspend and resume the top-level coroutine. The execution of the coroutine and the yielding from the coroutine comes back to the caller. In contrast, a stackful coroutine reserves a default stack for 1MB on Windows, and 2MB
on Linux.

## Thread Synchronization with Coroutines
Condition variables have many inherent risks such as spurious wakeup and lost wakeup.

### Lost Wakeup and Spurious Wakeup
* Lost wakeup: The sender sends its notification before the receiver is the wait state. The consequence is that the notification is lost. 
* Spurious wakeup: It may happen that the receiver wakes up, although no notification happened.


## C++20: Coroutines with cppcoro
Currently, cppcoro is based on the coroutines TS frameworks and can be used on Windows (Visual Studio 2017) or Linux (Clang 5.0/6.0 and libc++).
-std=c++17: support for C++17
-fcoroutines-ts: support for C++ coroutines TS
-Iinclude: cppcoro headers
-stdlib=libc++: LLVM implementation of the standard library
libcppcoro.a: cppcoro library


## C++20: Powerful Coroutines with cppcoro

### single_consumer_event
### Cancellation
### async_mutex

## C++20: Thread Pools with cppcoro
### when_all
static_thread_pool

