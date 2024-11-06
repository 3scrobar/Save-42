#!/usr/bin/bash

while true; do
git add .
sleep 1
git commit -m "autosave $(DATE)"
sleep 1
git push
sleep 120
done
