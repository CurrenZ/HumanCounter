from __future__ import print_function
from imutils.object_detection import non_max_suppression
import numpy as np
import imutils
import cv2
import threading
from tkinter import *

padding = 8
total_num = 0


def num_update(face_num, body_num):
    root = Tk()
    root.title("Detection Results")
    root.resizable(0, 0)

    face_lb = Label(root, text="Number of faces detected:")
    num_face_lb = Label(root, text=str(face_num))
    body_lb = Label(root, text="Number of bodies detected:")
    num_body_lb = Label(root, text=str(body_num))
    bt_close = Button(root, text="Close", command=root.destroy)
    tot_lb = Label(root, text="The total number of human:")
    tot_num_lb = Label(root, text=str(total_num))

    num_face_lb.config(font=("",25))
    num_body_lb.config(font=("",25))
    tot_num_lb.config(font=("", 25))

    face_lb.grid(row=0, column=0, padx=padding, pady=padding)
    num_face_lb.grid(row=0, column=1, padx=padding, pady=padding)
    body_lb.grid(row=1, column=0, padx=padding, pady=padding)
    num_body_lb.grid(row=1, column=1, padx=padding, pady=padding)
    tot_lb.grid(row=2, column=0, padx=padding, pady=padding)
    tot_num_lb.grid(row=2, column=1, padx=padding, pady=padding)
    bt_close.grid(row=3, column=2, padx=padding, pady=padding)

    root.mainloop()
    return


face_cascade = cv2.CascadeClassifier('C:\OpenCV-3.3.0\opencv\sources\data\haarcascades\haarcascade_frontalface_default.xml')

# initialize the HOG descriptor/person detector
hog = cv2.HOGDescriptor()
hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

# loop over the image paths
imagePath = sys.argv[1]

image = cv2.imread(imagePath)

faces = face_cascade.detectMultiScale(image, 1.3, 5)
for (x,y,w,h) in faces:
    cv2.rectangle(image,(x,y),(x+w,y+h),(255,0,0),2)

image = imutils.resize(image, width=min(400, image.shape[1]))
orig = image.copy()

# detect people in the image
(rects, weights) = hog.detectMultiScale(image, winStride=(4, 4),
    padding=(8, 8), scale=1.05)

# draw the original bounding boxes
for (x, y, w, h) in rects:
    cv2.rectangle(orig, (x, y), (x + w, y + h), (0, 0, 255), 2)

# apply non-maxima suppression to the bounding boxes using a
# fairly large overlap threshold to try to maintain overlapping
# boxes that are still people
rects = np.array([[x, y, x + w, y + h] for (x, y, w, h) in rects])
pick = non_max_suppression(rects, probs=None, overlapThresh=0.65)

# draw the final bounding boxes
for (xA, yA, xB, yB) in pick:
    cv2.rectangle(image, (xA, yA), (xB, yB), (0, 255, 0), 2)

image = imutils.resize(image, width=800)

threads = []
t = threading.Thread(target=num_update, args=(len(faces), len(pick)))
threads.append(t)
t.start()

cv2.imshow("Image", image)
c = cv2.waitKey(0)