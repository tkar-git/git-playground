# Git Play Ground

This is a repository for you to familiarize yourself with git. Some intructions/commands below introduce you to the very basics of git. But of course there's much more...

## Git User Configuration (to be done once on a machine)

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
git clone https://gitlab.com/tamasigithub/REPO_upd.git

```
Carefully enter the correct *email-id* followed by the *password* associated with your gitlab account.

```
cd gitplayground
```

---
Advanced:
Skip this if you are doing this tutorial for the first time.

You want to avoid adding username and password everytime?

Add ssh-keys to your profile:
- [ ] Click on your profile picture or initial if you do not have a profile picture
- [ ] Next click on `Edit profile` followed by `SSH Keys` and `Add new key`
- [ ] Next to generate an SSH key on your machine follow instructions under `Learn more` or click [here](https://gitlab.rlp.net/help/user/ssh.md)

Now clone the repository using ssh instead of https
```
git clone git@gitlab.com:tamasigithub/REPO_upd.git
```
---

## Let's create a new branch

The main branch of a repository is typically called either `main` or `master` branch. This branch should in principle hold a non buggy code that compiles and is error free.
Therefore, every user/developer who is working on a specific task should create his/her own branch. I will call my branch `dev_tamasi`, where dev corresponds to development.

```
git branch dev_tamasi
git checkout dev_tamasi
```
The branch command above creates a new local branch with the branch name *e.g. dev_tamasi* and the checkout command switches to this local branch.
You can do the above two steps in a single step using the following:

```
git checkout -b <your_branch_name>

```

You can check on which branch you are using the command `git branch`. You can also do `git branch -vv` to check which remote branch you are tracking.

## Backup your changes

Let's add something to your newly created branch:

You can, for example, just create a txt file and add some content to it using your favourite editor.
You could also copy your root exercises (c++ files) to your branch.

```
touch test.txt

```

You'll frequently use the command `git status` to check for the files you have modified and have or have not backedup. Let's check!

```
git status
git add test.txt
git commit -m "YAY my first git commit :)"
git push --set-upstream origin dev_tamasi

```
The *add* command stages the changes of your local branch to be committed using the next command with a **meaningfull message**.
The *push* command not only pushes your commits to a remote repository but also sets the local repositories tracking head to the specified remote branch name (in this case also `dev_tamasi`).

## Tracking a different remote branch (e.g. main or master)

```
git branch -u origin/master
```

## Pushing your changes to remote

```
git push origin HEAD
```

## Pulling from a different remote branch than the upstream branch

```
git pull origin <remote_branch_name>
```

## Merging your changes into remote master

The best and the recommended way to do this is to create a merge request after ensuring no bugs/errors.


## How to avoid adding large size files (e.g. Data files / build files / etc.)  

You can create a **.gitignore** file in your repository and add the extensions of the files/folders you don't want to add.

For example: you can use your favourite editor and add the following to *.gitignore* to ignore adding/pushing txt and root files to remote.

```
*.txt
*.root
```

## Merge conflicts

Merge conflits can occur when competing changes are made to the same line of a file or when one user edits a file and another user deletes the same file.

For example, modify the existing text in **mergeTest.txt** file.

You can now add your changes to your branch and hit git status.

```
git add mergeTest.txt
git commit -m "random text in mergeTest"
git push
git status
```

Next, in the main branch I will modify the same file again and push my changes.

```
git status
git pull origin main
```

You should have now created a merge conflict. Open the file in which the merge conflict has arised and fix it.

## Contact

Tamasi Kar, University of Heidelberg

kar@physi.uni-heidelberg.de
