# TensorFlow and tf.keras
import tensorflow as tf

# Helper libraries
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image


print(tf.__version__)

ImageName=[]
Labels=[]

for chiffre in range(0,10):
    for indice in range(0,21):
        ImageName.append('./../../Database/Prof/Images/bmpProcessedSeuil/' + str (chiffre) +"_" +str (indice)+".bmp")
        Labels.append (chiffre)
print(Labels)

images = [np.array(Image.open(str(l))) for l in ImageName]
images = np.sum(images,axis=3)//3/255

plt.figure()
plt.imshow(images[0])
plt.colorbar()
plt.grid(False)
plt.show()