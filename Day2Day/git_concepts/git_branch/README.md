</h1>Git branch </h1>
<p>
A branch is a version of the repository that diverges from the main working project. It is a feature available in most modern version control systems. A Git project can have more than one branch. These branches are a pointer to a snapshot of your changes. When you want to add a new feature or fix a bug, you spawn a new branch to summarize your changes. So, it is complex to merge the unstable code with the main code base and also facilitates you to clean up your future history before merging with the main branch.
</p>

<h1>Git Master Branch</h1>
<p>
The master branch is a default branch in Git. It is instantiated when first commit made on the project. When you make the first commit, you're given a master branch to the starting commit point. When you start making a commit, then master branch pointer automatically moves forward. A repository can have only one master branch.

Master branch is the branch in which all the changes eventually get merged back. It can be called as an official working version of your project.
</p>



<h1>create branch </h1>
<p>
	You can create a new branch with the help of the git branch command. This command will be used as:
	
	git branch  <branch name>  

	This command will create the branch B1 locally in Git directory.
</p>

<h1>list existing branches </h1>
<p>
	You can List all of the available branches in your repository by using the following command.

	Either we can use git branch - list or git branch command to list the available branches in the repository.
	
	git branch --list  or
	
	git branch
	
</p>

<h1>Delete Branch</h1>
<p>
	You can delete the specified branch. It is a safe operation. In this command, Git prevents you from deleting the branch if 
	
	it has unmerged changes. Below is the command to do this.

	git branch -d <branch name>  or

	git branch -D <branch name>
</p>

<h1>Delete Remote Branch </h1>
<p>
	You can delete a remote branch from Git desktop application. Below command is used to delete a remote branch:

	git push origin -delete <branch name>  
</p>

<h1>Switch branch</h1>
<p>
	Git allows you to switch between the branches without making a commit. You can switch between two branches with the git chec
	
	kout command. To switch between the branches, below command is used: 
	
	git checkout<branch name>  

	Switch from master Branch

	You can switch from master to any other branch available on your repository without making any commit.
	
	git branch -m master  
</p>

<h1>Rename branch</h1>
<p>
	We can rename the branch with the help of the git branch command. To rename a branch, use the below command: 
	
	git branch -m <old branch name><new branch name>  

</p>

<h1>Merge branch</h1>
<p>
	Git allows you to merge the other branch with the currently active branch. 
	
	You can merge two branches with the help of git merge command. Below command is used to merge the branches:
	
	git merge <branch name> 
</p>


