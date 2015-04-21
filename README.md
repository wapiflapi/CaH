This are the source files for the c@h CTF organized by security enthousiasts from Epitech Toulouse. The event was held in Toulouse in April 2015. Those who played didn't solve everything, and those who didn't are missing out. Releasing the chalenges is our way to contribute to the fun everyone is having with CTFs since we started doing security. Thanks everyone in the community.

Challenges
==========

Challenges go from easy to fairly complicated, keeping in mind this was designed for a six hour CTF. No team solved everything and about 60% of the challenges where solved at least once during the ctf. We mostly have reverse, sploit and some web. There are some crypto/misc/stega challenges as well.

How to play
===========

You should probably avoid looking at the source code of the challenges. Each challenge is in its own folder with a `Makefile`. When you make two folders should be generated:
  - `player`: This folder was provided to the teams as a downloadable archive during the CTF.
  - `server`: This is where all the files needed on the server-side live.

Note that both those folders are optional, they might not make sense for all chalenges. Fore example web challenges don't have a `player` folder.

Most chalenges that need to run on the CTF servers provide a xinetd configuration file, there might be some exceptions with source code running directly on appache and/or php.

Contibute
=========

Please feel free to open an issue if you notice something strange or have a question. We are also on IRC on several channels (look for SiN, eax64, ampotos, BestPig and wapiflapi).

If you have writeups we'll be glad to link them here, please open an issue or PR.

