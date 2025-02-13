# 🪂 Parachute Model

Comparison of mathematical modeling of free fall with an exact model (differential equation) and an approximate one.

## 🎯 Objective

- Build a model developed in class to evaluate the speed of a parachutist who drops from a fixed point, assuming that wind resistance is linearly proportional to speed and acts upwards
- Demonstrate the efficiency of approximate methods, taking into account their limitations.

### Working project demo

Calculate de parachutist’s velocity based on the **exact model** 
<img width="550" alt="ParachuteModel_exact" src="https://github.com/user-attachments/assets/09f8f6a0-4ce2-4414-bd16-80295434d3ed" />

Calculate de parachutist’s velocity based on the **approximate model** 
<img width="550" alt="ParachuteModel_approximate" src="https://github.com/user-attachments/assets/ad58cd52-2f1f-4746-ba2c-95fc80d1510b" />

Compare the approximate model against the exact one.
<img width="550" alt="ParachuteModel_comparison" src="https://github.com/user-attachments/assets/52b3ad86-f715-4bb9-b573-988d20f68bc4" />

Salida del programa
<img width="550" alt="ParachuteModel_exit" src="https://github.com/user-attachments/assets/e8a87cfc-bad5-42ba-b1b8-d1cd3b6dd13b" />

## 🙌 Project Personal Milestones

- Undoubtedly, the implementation of the second model was a challenge since it was first approached as a recursive function. With the aim of avoiding a “segmentation fault” error as well as saving up time and memory resources, I opted to create a loop.  This loop called the non-recursive function that calculates the velocity and storages the previous value to calculate the following.
- Altogether, this activity ***showed me how real-life physical behavior can be accurately modeled with programming***. From understanding the physics involved in the problem, the process required to generate a mathematical model, the pros and cons of the different models we can create, the implementation challenges and finally the models’s results comparison.

## 💡 Inspiration for creating this project

This was one of the tasks I did for my Computing Languages II college course final project. In my project, I had to present along with my teammates the topic "CSV files" in C#. I did this program as an example excercice for the presentation.

I wanted to make a real life example of the CSV's capabilities, so I came up with the idea of a Movie Ticket Store after catching myself looking at my local movie theater schedule for watching a movie.

This program was an activity carried out in my Scientific Programming college course

## 👀 About the project

The free fall follows the following behaviour:

$$
\frac{dv}{dt}=\frac{mg-cv}{m}
$$

Where:

$m$: Mass [kg]

$g$: Gravity = 9.81 [$\frac{m}{s^{2}}$]

$c$: Air resistance constraint [N]

$v$: Speed [$\frac{m}{s}$]

$t$: Time [s]

<aside>
🎢

*The rate of change in respect to time to the velocity is proportionally direct to the force rate the air exerted to the object.*

</aside>

The following differential equation was built in class aiming to model exactly the parachutist velocity at any given moment in time:

$$
v(t)=\frac{gm}{c}(1-e^{\frac{-c}{m}t})
$$

Where:

$v$: Speed [$\frac{m}{s}$]

$t$: Time [s]

$g$: Gravity = 9.81 [$\frac{m}{s^{2}}$]

$m$: Mass [kg]

$c$: Air resistance constraint [N]

An approximate model was built as well to test how much does a non-differential equational approach differs from the exact real values. This model is a recursive function that obtains the velocity at a certain moment in time based on obtaining the previous x velocities with a given step.

$$
v(t_{i+1})=(g-\frac{cv_{ti}}{m})(t_{i+1}-t_{i})+v(t_{i})
$$

Where:

$v$: Speed [$\frac{m}{s}$]

$t$: Time [s]

$i$: current iteration

$g$: Gravity = 9.81 [$\frac{m}{s^{2}}$]

$m$: Mass [kg]

$c$: Air resistance constraint [N]

It is known that for both models the velocity at time 0 is equal to 0 ($v(0) = 0$).
