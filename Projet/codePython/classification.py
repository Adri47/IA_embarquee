# -*- coding: utf-8 -*-
"""Classification.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1gegfjFt49Gzjodzx0Dvh3nJG2NfBC0bY
"""

import os
import scipy
import matplotlib
import numpy

from PIL import Image
import IPython
import matplotlib.pyplot as plt

import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers

from google.colab import drive
drive.mount('/content/drive')

class_names = ['0','1', '2', '3', '4', '5','6', '7', '8', '9']

ImagePath=[]
train_labels=[]

for chiffre in range(0,10):#0 à 9
    for indice in range(0,20):#0 à 19
        ImagePath.append('/content/drive/MyDrive/EN343/EN343_source/Serveur/Projet/Database/Prof/Images/bmpProcessed/' + str (chiffre) +"_" +str (indice)+".bmp")
        train_labels.append (chiffre)
#print(Labels)

train_labels_tab = keras.utils.to_categorical(train_labels,10)
print("\n train_labels :\n")
print(train_labels_tab)

train_images = [numpy.array(Image.open(str(l))) for l in ImagePath]
train_images = numpy.sum(train_images,axis=3)//3/255

test_images_Path=[]
test_labels=[]

for chiffre in range(0,10):
        test_images_Path.append('/content/drive/MyDrive/EN343/EN343_source/Serveur/Projet/Database/Prof/Images/bmpProcessed/' + str (chiffre) +"_" +str (20)+".bmp")
        test_labels.append (chiffre)
#print(test_labels)
#print(test_images)
test_labels_tab = keras.utils.to_categorical(test_labels,10)
print("\n test_labels :\n")
print(test_labels_tab)

test_images = [numpy.array(Image.open(str(l))) for l in test_images_Path]
test_images = numpy.sum(test_images,axis=3)//3/255

plt.figure(figsize=(10,10))
for i in range(200):
    plt.subplot(10,20,i+1)
    plt.xticks([])
    plt.yticks([])
    plt.grid(False)
    plt.imshow(train_images[i], cmap=plt.cm.binary)
    plt.xlabel(class_names[train_labels[i]])
plt.show()

model = tf.keras.Sequential([
    tf.keras.layers.Flatten(input_shape=(28, 28)),
    tf.keras.layers.Dense(128, activation='relu'),
    tf.keras.layers.Dense(10,),
    tf.keras.layers.Activation("softmax")
])

model.compile(optimizer='adam',
              loss=tf.keras.losses.CategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

model.fit(train_images, train_labels_tab, epochs=8)

test_loss, test_acc = model.evaluate(test_images,  test_labels_tab, verbose=2)

print('\nTest accuracy:', test_acc)

probability_model = tf.keras.Sequential([model, 
                                         tf.keras.layers.Softmax()])

predictions = probability_model.predict(test_images)

numpy.argmax(predictions[0])
#predictions[0]

test_labels[0]

def plot_image(i, predictions_array, true_label, img):
  true_label, img = true_label[i], img[i]
  plt.grid(False)
  plt.xticks([])
  plt.yticks([])

  plt.imshow(img, cmap=plt.cm.binary)

  predicted_label = numpy.argmax(predictions_array)
  if predicted_label == true_label:
    color = 'blue'
  else:
    color = 'red'

  plt.xlabel("{} {:2.0f}% ({})".format(class_names[predicted_label],
                                100*numpy.max(predictions_array),
                                class_names[true_label]),
                                color=color)

def plot_value_array(i, predictions_array, true_label):
  true_label = true_label[i]
  plt.grid(False)
  plt.xticks(range(10))
  plt.yticks([])
  thisplot = plt.bar(range(10), predictions_array, color="#777777")
  plt.ylim([0, 1])
  predicted_label = numpy.argmax(predictions_array)

  thisplot[predicted_label].set_color('red')
  thisplot[true_label].set_color('blue')

i = 0
plt.figure(figsize=(6,3))
plt.subplot(1,2,1)
plot_image(i, predictions[i], test_labels, test_images)
plt.subplot(1,2,2)
plot_value_array(i, predictions[i],  test_labels)
plt.show()

i = 9
plt.figure(figsize=(6,3))
plt.subplot(1,2,1)
plot_image(i, predictions[i], test_labels, test_images)
plt.subplot(1,2,2)
plot_value_array(i, predictions[i],  test_labels)
plt.show()

# Plot the first X test images, their predicted labels, and the true labels.
# Color correct predictions in blue and incorrect predictions in red.
num_rows = 2
num_cols = 5
num_images = num_rows*num_cols
plt.figure(figsize=(2*2*num_cols, 2*num_rows))
for i in range(num_images):
  plt.subplot(num_rows, 2*num_cols, 2*i+1)
  plot_image(i, predictions[i], test_labels, test_images)
  plt.subplot(num_rows, 2*num_cols, 2*i+2)
  plot_value_array(i, predictions[i], test_labels)
plt.tight_layout()
plt.show()

# Grab an image from the test dataset.
img = test_images[1]

print(img.shape)

img = (numpy.expand_dims(img,0))

print(img.shape)

predictions_single = probability_model.predict(img)

print(predictions_single)

plot_value_array(1, predictions_single[0], test_labels)
_ = plt.xticks(range(10), class_names, rotation=45)
plt.show()

numpy.argmax(predictions_single[0])

weight1, biais1 =model.layers[1].get_weights()
weight2, biais2 =model.layers[2].get_weights()

weight1 = numpy.array(weight1)
weight2 = numpy.array(weight2)
numpy.savetxt("./drive/MyDrive/EN343/poids_1.txt",weight1.T)
numpy.savetxt("./drive/MyDrive/EN343/poids_2.txt",weight2.T)
numpy.savetxt("./drive/MyDrive/EN343/biais_1.txt",numpy.array(biais1))
numpy.savetxt("./drive/MyDrive/EN343/biais_2.txt",numpy.array(biais2))