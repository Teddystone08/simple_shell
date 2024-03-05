#!/bin/bash

max_pid=$(cat /proc/sys/kernel/pid_max)
echo "Maximum process ID:$max_pid"
