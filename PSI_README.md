# Git Play Ground

This is a repository for you to familiarize yourself with git. Some intructions/commands below introduce you to the very basics of git. But of course there's much more...

## First Things: Git User Configuration

#### Have you already configured git with your user information on this machine?
Note that the configuration needs to be done only once on a machine

- [ ] If you do not remember, check using the following command:

```
git config --list

```

- [ ] If you do not see your user.name and user.email configure using:

```
git config --global user.name "Your Name"
git config --global user.email "your@email.com"

```

Here *Your Name* and *your@email.com* will be attached to your commits and tags.


## Clone this repository

You can clone this repository, create your own branch and add text files/ codes etc.

```
git clone https://gitlab.rlp.net/psi2023/gitplayground.git

```
Carefully enter the correct *email-id* and *password* associated with your rlp gitlab account.

---
Advanced:

You want to avoid adding username and password everytime?

Add ssh-keys to your profile:
- [ ] Click on your profile picture or initial if you do not have a profile picture
- [ ] Next click on `Edit profile` followed by `SSH Keys` and `Add new key`
- [ ] Next to generate an SSH key on your machine follow instructions under `Learn more` or click [here](https://gitlab.rlp.net/help/user/ssh.md)
---

## Let's create a new branch

The main branch of a repository is typically called either `main` or `master` branch. This branch should in principle hold a non buggy code that compiles and is error free.
Therefore, every user/developer who is working of a specific task should create his/her own branch. I will call my branch `dev_tamasi`, where dev corresponds to development.

```
git branch dev_tamasi
git checkout dev_tamasi
```
The branch command above creates a new local branch with the branch name *e.g. dev_tamasi* and the checkout command switches to this local branch.
You can do the above two steps in a single step using the following:

```
git checkout -b dev_tamasi

```

You can check on which branch you are using the command `git branch`

## Backup your changes

Let's add something to your newly created branch:


## Tracking a different remote branch (e.g. master)



## Pushing your changes to remote

```
git push origin HEAD
```

## Merging your changes into master


## Avoid adding large size files (e.g. Data files / build files / etc.)  


