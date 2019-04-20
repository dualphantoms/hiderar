
# hiderar
Embeds a RAR file into a JPG file.</br>
Based on this image: </br>
![chanchanchanchan](https://i.imgur.com/u0rgD.jpg)
</br>
Instead of using batch to simply write copy the files like in the image, this uses c++ to embed the file. Works by reading the datastream of the jpg file, extending it's size to include the length of the rar file. Writes rar file data after the jpg EOF header. </br>
