# Smart Lift System using CCTV Camera

The general concept of modern elevators, which became widely exploitable some 150 years ago, has regardless of many technological advancements remained mostly the same. The typical elevator still needs travelers to press the respective arrow buttons and wait for some time for the lift to come. If at some floor there’s a huge crowd waiting for the lift, they stand randomly creating a mess for the people coming out of the lift. And as there is no queue it is very difficult for someone from the back to check whether his desired button(up/down) is pressed or not.

# A new Habit - Maintain 2 Queues infront of lift on each floor

If you are in the left Queue - it would mean that you wish to go to upper floors AND if you are in the right queue would mean that you wish to go to lower floors.

The Smart Lift system using CCTV Camera is a novel approach to optimize lift operations in multi-floor buildings. The system utilizes CCTV cameras installed above the lift's entrance on each floor, which capture frames and divide them into left and right halves. These halves are then analysed to detect the presence of a person using facial recognition technology. Based on the location of the detected person, the system sends signals to the moving lift to press the appropriate direction button, either up or down.

# Setup

1. Raspberry pi connected to pi's camera module, Arduino and keyboard, mouse, monitor, power cable, etheret cable.
![image](https://github.com/rachelgupta/Smart-Lift-System-using-CCTV-Camera/assets/83275253/c8d49564-ded5-4dd9-a2c6-63b6877fd35e)

2. Arduino depecting lift, connecting to a LED through breadboard.
![image](https://github.com/rachelgupta/Smart-Lift-System-using-CCTV-Camera/assets/83275253/24c78a88-1d5a-4f11-a349-5d73f2d68d0a)


# Resuts
(Movement of lift to differnet floors is done using Arduino)

Step 1: The 'FaceDetection.py' code is made to run. Point your face to the raspberry pi camera

![image](https://github.com/rachelgupta/Smart-Lift-System-using-CCTV-Camera/assets/83275253/82bcd8b1-03b5-4389-9cea-d5c17319a880)

This image is saved and given to our python code.

Step 2: FaceDetection.py is our python code that takes the image, detects faces on the right and left half, prints the number of faces and sends signal to our Arduino through serial port.

 ![image](https://github.com/rachelgupta/Smart-Lift-System-using-CCTV-Camera/assets/83275253/6291dbfa-f1c4-4e36-bfd5-dd8469818456)

As the image above has face on the right side, it has counted the face and printed it. You can see the right half image and the square over the face in the below picture.

![image](https://github.com/rachelgupta/Smart-Lift-System-using-CCTV-Camera/assets/83275253/e9f4c06c-d595-4457-83cf-c9419164ccc8)

Step 3: In a real-world scenario, the elevator would be functioning normally, which means it would travel to different floors when a button is pressed. Now our 'smartlift.ino' code comes into play at this stage. Previously, the elevator was positioned on the 9th floor, and now we have summoned it to the 1st floor.

![image](https://github.com/rachelgupta/Smart-Lift-System-using-CCTV-Camera/assets/83275253/b79bd2ef-8842-4e9b-a40a-3c66a05ca6cf)

Step 4: But now when our python code ran, it sent a signal to Arduino that someone is wating at the 5th floor who wants to go down(as the person is on the right), hence the lift must stop.

![image](https://github.com/rachelgupta/Smart-Lift-System-using-CCTV-Camera/assets/83275253/d6ea3d19-584e-479a-a700-24b816397c92)

Step 5: When the lift reaches that floor, the LED blinks.

![image](https://github.com/rachelgupta/Smart-Lift-System-using-CCTV-Camera/assets/83275253/887cbb06-a0b9-4ce2-a4d7-2ca2290f7233)

# Advantages
The Smart Lift system offers several advantages over traditional lift systems. It reduces the waiting time for passengers by automatically pressing the correct direction button based on the location of the detected person. This helps in optimizing lift operations and improving overall efficiency. The system also eliminates the need for passengers to press the lift buttons manually, reducing the risk of disease transmission through touch surfaces, especially in the current era of heightened hygiene awareness.

The proposed system can be easily integrated into existing lift systems with minimal modifications, as it utilizes standard CCTV cameras that are commonly installed in buildings for security purposes. It can be deployed in various settings such as residential buildings, office complexes, hospitals, and malls to enhance the convenience and safety of lift operations.





