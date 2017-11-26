from __future__ import print_function
from imutils.object_detection import non_max_suppression
import numpy as np
import imutils
import cv2
import threading
from tkinter import *

threads = []

padding = 8
isVideo = FALSE
windows_title = "Image"


def result_window(facenum, bodynum, totnum):
    root = Tk()
    root.title("Detection Results")
    root.resizable(0, 0)

    face_lb = Label(root, text="Number of faces detected:")
    num_face_lb = Label(root, text=str(facenum))
    body_lb = Label(root, text="Number of bodies detected:")
    num_body_lb = Label(root, text=str(bodynum))
    bt_close = Button(root, text="Close", command=root.destroy)
    tot_lb = Label(root, text="The total number of human:")
    tot_num_lb = Label(root, text=str(totnum))

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
filepath = sys.argv[1]
extension = filepath.split(".")[-1]

# determine if the file is a video
if (extension == 'avi' or 'mp4'):
    isVideo = TRUE
    windows_title = "Footage"
    cap = cv2.VideoCapture(filepath)

while(cap.isOpened() and isVideo):

    ret, frame = cap.read()
    faces = face_cascade.detectMultiScale(frame, 1.3, 5)
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

    orig = frame.copy()

    # detect people in the image
    (rects, weights) = hog.detectMultiScale(frame, winStride=(4, 4),
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
        cv2.rectangle(frame, (xA, yA), (xB, yB), (0, 255, 0), 2)

    #t = threading.Thread(target=result_window, args=(len(faces), len(pick), len(faces)+len(pick)))

    cv2.imshow(windows_title, frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break


cap.release()
cv2.destroyAllWindows()
