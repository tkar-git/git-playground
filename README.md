# REPO_upd

## HOLA Sonam!

#### I guess you are here to clone me ;)

#### But have you already added the ssh keys to make ssh cloning possible?
Follow the instructions on the link below: 
<br /> https://gitlab.com/help/ssh/README#generating-a-new-ssh-key-pair

If you have a github account and the admin of the repository(which is **tamasigithub** for this repository)
then you can have a look at the contents here:
https://gitlab.com/tamasigithub/REPO_upd
<br /> On the right side you will see a blue button 'clone' either with ssh(recomended) or https

Click on that and copy the link

Next go to the directory where you would like to clone this repository and type
<br /> ***git clone git@gitlab.com:tamasigithub/REPO_upd.git***

#### I just created a new branch ;) 
I did the following to create a new branch:
<br /> ***git branch tamasi ***

You can list all the branches you have in your repo by doing
<br /> ***git branch***
<br /> It prints the following for me:
<br /> \*master
<br /> tamasi

To switch to the newly created branch 'tamasi' do
<br \> ***git checkout tamasi***

You can now create a new test file
<br \> ***touch test.txt***

***git add test.txt***

***git status***

***git commit -m "hurray my first test text file ;)"***

***git push --set-upstream origin tamasi***

This has now updated your changes to the remote repository -> GO CHECK!

#### To pull updates from the master branch do
<br /> ***git pull origin master***

If your branch and master branch are different (which might be the case),
it will complain saying there is a conflict in some file
<br /> you will have to fix this conflict first
<br /> There are some instructions here:
<br /> https://help.github.com/en/articles/resolving-a-merge-conflict-using-the-command-line 
<br /> https://docs.gitlab.com/ee/university/training/topics/merge_conflicts.html

You can **switch b/w master and your local branch** by doing
<br /> ***git branch*** 
<br /> This will list all the branches and highlight the branch you are presently working on

if your local branch'tamasi' is highlighted in green  then doing 
<br /> ***git checkout master*** will switch to master 

You can switch back to your local branch by doing 
<br /> ***git checkout tamasi***

Now it's time to learn how to merge your local branch changes to master

I have'nt done it before.. I am learning too I will do it slowly
<br /> First switch to the master branch
<br /> ***git checkout master***

next pass the merge command
<br /> ***git merge tamasi***

if you want to checkout a specific remote branch from a repository
<br /> clone the master branch and do :
<br /> ***git checkout --track origin/<name_of_remote_branch>***
