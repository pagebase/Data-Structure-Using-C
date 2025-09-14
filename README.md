# Create new branch and jump into it.
`git checkout -b Patch1`
# Push new local branch onto remote
`git push -u origin Branch_Name`
# List local branch
`git branch`
# List remote branch
`git branch -r`
# Merge branch
> 1. Switch to the branch you want to merge into
>> `git checkout main`
> 2. Merge the other branch into this one
>> `git merge feature-branch`
> 3. Push the merged result
>> `git push origin main`
# Delete remote branch
`git push origin --delete branch-name`
# Delete local branch
`git branch -D branch-name`
