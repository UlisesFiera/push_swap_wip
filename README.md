Welcome, human.

'git push' shortcut:
git config --global alias.upload '!git add . && git commit -m "v0.2wip" && git push'

'valgrind' command:

valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap

try!
ARG=$(seq 0 100 | sort -R | tr '\n' ' ') && ./push_swap $ARG | wc -l

checker
ARG="4 10 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG