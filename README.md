# Git Play Ground

This is a repository for you to familiarize yourself with git. Some instructions/commands below introduce you to the very basics of git. But of course there's much more...
## Setting up your git environment

### Create a GitHub account
If you do not have one follow the instructions [here](https://docs.github.com/en/get-started/start-your-journey/creating-an-account-on-github) to create a GitHub account.

### Add your SSH key to your GitHub account
This step is optional but highly recommended if you want to avoid entering username and password every time you push (pull) to (from) remote.
</br>
It includes the following steps:
1. Generate an SSH key on your machine (steps 1 and 2 of [prerequisites](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account?tool=webui#prerequisites))
2. Add the SSH key to your GitHub account (steps 1-9 of [Adding a new SSH key to your account](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account?tool=webui#adding-a-new-ssh-key-to-your-account))
Follow the instructions [here](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account?tool=webui&platform=linux) to add SSH key to your GitHub account.

### Install git
Follow the instructions [here](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) to install git on your machine.
You can also use the docker container we created previously. The container has git installed and is ready to use.

Windows users should use the Unix subsystem (WSL) terminal (e.g. Ubuntu) and follow install instructions for Linux.

Check git installation by running `git --version` in your terminal. You should see the version of git installed on your machine.

### Configure git (to be done once on a machine)

Have you already configured git with your user information on this machine?
</br>
Note that the configuration needs to be done only once on a machine

- If you do not remember, check using the following command:

```bash
git config --list
```

- If you do not see your user.name and user.email configure using:

```
git config --global user.name "Your Name"
git config --global user.email "your@email.com"
```

Here *Your Name* and *your@email.com* will be attached to your commits and tags.

## Clone the repository
- If you haven't already done so, clone the repository using the ssh link below.:

```
git clone git@github.com:tkar-git/git-playground.git
```
- OR HTTPS link:
```
git clone https://github.com/tkar-git/git-playground.git
```

- Switch to the working directory and check the contents of the repository
```
cd git-playground && ls -l
```
## Let's do some monitoring
- You can check the status of your repository using the command:

```
git status
```
- You can list all branches using the command below. Add `-a` flag to also list remote branches. 

```
git branch
```
## Creating a new branch

The main branch of a repository is typically called either `main` or `master` branch. This branch should in principle hold a non-buggy code that compiles and is error free.
Therefore, every user/developer who is working on a specific task should create his/her own branch. I will call my branch `dev_tkar`, where dev corresponds to development.

```
git branch dev_tkar
git checkout dev_tkar
```
The branch command above creates a new local branch with the branch name *e.g. dev_tkar* and the checkout command switches to this local branch.
You can do the above two steps in a single step using the following:

```
git checkout -b <your_branch_name>
```

You can check, which branch the `HEAD` points to (working branch) using the command `git branch`. You can also do `git branch -vv` to check which remote branch you are tracking.

## Backup your changes

Let's add something to your newly created branch:

You can, for example, just create a txt file and add some content to it using your favourite editor.
You could also copy your old exercises (c++/python files) to your branch.

```
touch test.txt
```

You'll frequently use the command `git status` to check for the files you have modified and have or have not backed-up. Let's check!

```
git status
git add test.txt
git commit -m "YAY my first git commit :)"
git push --set-upstream origin dev_tkar
```
The *add* command stages the changes of your local branch to be committed using the next command with a **meaningfull message**.
The *push* command not only pushes your commits to a remote repository but also sets the local repositories tracking head to the specified remote branch name (in this case also `dev_tkar`).

- (Optional) You can track a different remote branch (e.g. main or master) by setting a different upstream branch using the following command:

```
git branch -u origin/master
```

## Pushing your changes to remote
- Wait! Don't forget to pull the latest changes from the remote repository before pushing your changes. This is important to avoid merge conflicts.

```
git pull
git push origin HEAD
```

- Pulling from a different remote branch than the upstream branch e.g. <remote_branch_name> = `master` or `main`:

```
git pull origin <remote_branch_name>
```
- Not able to push your changes? Ask the owner of the repository to add you as a collaborator -- OR -- create a `fork` of the repository and push your changes to your own fork. You can then create a `pull request` to merge your changes into the original repository.

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

Merge conflicts can occur when competing changes are made to the same line of a file or when one user edits a file and another user deletes the same file.

For example, modify the existing text in **mergeTest.txt** file.

You can now add your changes to your branch and hit git status.

```
git add mergeTest.txt
git commit -m "random text in mergeTest"
git push
git status
```

Next, in the master branch I will modify the same file again and push my changes.

```
git status
git pull origin main
```

You should have now created a merge conflict. Open the file in which the merge conflict has occurred and fix it.

## Contact

Tamasi Kar, University of Heidelberg

kar@physi.uni-heidelberg.de
