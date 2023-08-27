import cv2
import serial
import time

#Load the image
img = cv2.imread('image4.jpg')

#Get the dimensions of the image
height, width, channels = img.shape

#split the image into 2 halves
left_half = img[0:height,0:int(width/2)]
right_half = img[0:height,int(width/2):width]

#Load the face detection classifier
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

#Detect face in the left half
left_gray = cv2.cvtColor(left_half,cv2.COLOR_BGR2GRAY)
left_faces = face_cascade.detectMultiScale(left_gray,scaleFactor=1.1, minNeighbours=5)

#Detect face in the right half
right_gray = cv2.cvtColor(right_half,cv2.COLOR_BGR2GRAY)
right_faces = face_cascade.detectMultiScale(right_gray,scaleFactor=1.1, minNeighbours=5)

#Print the number of faces in each half
print("Number of faces in left half: ",len(left_faces))
print("Number of faces in right half: ",len(right_faces))

ser = serial.Serial('/dev/ttyUSB0',baudrate=9600)
time.sleep(2)

if(len(left_faces)>0 and len(right_faces)>0):
    ser.write(b'a')
elif(len(left_faces)>0):
    ser.write(b'b')
elif(len(right_faces)>0):
    ser.write(b'c')
else:
    ser.write(b'd')
    print('No face detected')

ser.close()

#Display the image and draw rectangles around the detected faces
for(x,y,w,h) in left_faces:
    cv2.rectangle(left_half,(x,y),(x+w,y+h),(255,0,0),2)
for(x,y,w,h) in right_faces:
    cv2.rectangle(right_half,(x,y),(x+w,y+h),(255,0,0),2)

#Displaying the two halves side by side
cv2.imshow('Left half',left_half)
cv2.imshow('Right half',right_half)
cv2.waitKey(0)
cv2.destroyAllWindows()