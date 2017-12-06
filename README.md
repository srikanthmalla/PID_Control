# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

Step1: Run your udacity simulator

Step2: Run ./start.sh in src folder


## About PID Control

A PID (Proportional, Integral, Derivative) controller is a control loop feedback controller which is widely used in different control systems.

Error is an input variable for the controller:

cte = desired_state - measured_state

With the proportional band (P) only, the PID controller output is proportional to the cte. It takes into account only the present value of cte. Thanks to this part of controller, it is able to steer in the correct direction.

Integral term (I) takes into account the integral of cte over the past time. It is used to reduce systematic bias. we do not need to compute the integral for all time, but calculate it over only last n frames. In other case, we can accumulate errors because of left turns prevalens which can result in different behaviour of the controller during multi lap drive and even going off the track. A buffer was implemented for the purpose using calloc.

With derivative (D) part, the controller output is proportional to the rate of change of cte (its derivative). The parameter is used to reduce overshooting and dump oscillations caused by the P.

While the PID controller is easy to implement, but it is not so easy to tune.

## How it was tuned

Initially, the controller was tuned with so-called Ziegler–Nichols method. Generally speaking, it requires to set Kd and Ki to 0 and gradually increase Kp before the car runs with stable and consistent oscillations. This value of Kp and the oscillation period can be used to calculate optimal pid controller parameters by the method. Unfortunatly, the controller with resulted parameters was able to drive car around the track but with a lot of wobbling. That is why, parameters were further tuned manually by try-and-error process.

The same process was applied for differnt speed, so different PID parameters were found for different speed. The results were linearized The same process was applied for different speed, so different PID parameters were found for different speed. The results were linearized in order to make the parameters automatically tune with the car speed variation.

The implementation also takes into account different time intervals between data frames.

