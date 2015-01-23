# QtPhysicsSandbox:
A small physics sandbox using Qt and C++. (WIP)

## What's Been Done:
* The UI framework is finished and just needs polishing. An introductory guide will be posted on how to use it at a later date.
* Basic item generation in the preview window is almost complete. Still need to flush out the preview class and improve rendering. 
* Drag and dropping into the main window is about 50% done. Currently, the objects aren't dropped at the cursor location. This should be an easy fix though. Right now, the mime data from the cursor holds a byte array for the entire item which is incredibly unsafe and is meant for demonstration purposes only. I plan on creating a seperate object entirely and deleting the preview object. 

## What Will Be Done:
* First on the to-do list is finishing the drag and drop feature. I plan on implementing custom mime data that stores the properties from the preview window set by the user. The drop point of the mouse will then create a new object based on the mime data. 
* Implement more complex items.
* Implement basic physics such as gravity and collision.
* Art by Jordan Fest will be added to the objects as soon as I get the basic rendering working properly.
* Variable environmental properties.
* Basic pen tools for drawing boundries and walls.

## Developer's Note
I'm going to be putting this project on the back burner for a little bit. I'm not abandoning it entirely, but there's some other projects that I come up that I need to attend to before I can focus all my attention on this. I will still commit to this project when I have time, but updates will be slower than they have been. 
