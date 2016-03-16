function [Error] = calculateActuatorFeasibility(Coefficients, Mass, Moment, MaxVel, MaxForce, MaxAngle, tf)
%UNTITLED4 Summary of this function goes here
%   This function will test a given set of polynomials to see if they fit
%   within the actuator constraints specified
%   ESSENTIALLY
%   Coefficients: a 3X10 Matrix of coefficients
%   Mass
%   Moment - vector
%   tf: the final time

g = 9.81;

% Find the maximum accelerations
maxima = calculateMaximums(Coefficients, 2, tf);
%now test whether these maximums are within feasible limits
for it = (1:length(maxima))
    %calculate the magnitude of the acceleration gravity while taking into
    %account mass and gravity
    %mag is the [0, 0, 0, F_Total]' vector of the quadrotor. It must not
    %exceed the maximum possible acceleration
    mag = norm(Mass * (maxima(:, it) + [0; 0; g]));
    if mag > MaxForce
        fprintf('FORCE TOO HIGH\n');
        Error = 1;
        return
    else
%         %since it appears that the magnitude of the force is possible
%         %fprintf('Magnitude of force within reasonable limits') calculate
%         %the Fi and Fb vectors and check Fb's sign also calculate the unit
%         %vectors and possibly recalculate them
%         Fb = [0;0;mag];
%         Fi = Mass * (maxima(:, it) + [0; 0; g]);
%         Fb_bar = Fb / norm(Fb);
%         Fi_bar = Fi / norm(Fi);
%         %checking the sign of Fb
%         if Fi'*Fb < 0
%             Fb = -1 * Fb;
%             Fb_bar = Fb / norm(Fb);
%         end
%         
%         %now calculate the approx_Qd
%         approx_Qd = (1/(sqrt(2 * (1 + Fi_bar' * Fb_bar)))) * [1 + Fi_bar' * Fb_bar; cross(Fi_bar, Fb_bar)];
%         %factor yaw into the quarternion Qd this will find the current yaw
%         %and bring it back to zero with a quat mult
%         attitude_radians = quat2eul(approx_Qd');
%         Qd = quatmultiply(approx_Qd', [cos(-(attitude_radians(1))/2), 0, 0, sin(-(attitude_radians(1))/2)]);
%         %convert the quarternion to euler angles and check if it is also
%         %within reasonable limits ZYX!
%         attitude_radians = quat2eul(Qd);
%         %check the angle if too large report it and return
%         if abs(attitude_radians(2)) > MaxAngle || abs(attitude_radians(3)) > MaxAngle
%            fprintf('ANGLE TOO LARGE\n');
%            Error = 1;
%            return;
%         end
    end
end


%IF YOU HAVE NOT RETURNED BY THIS POINT THE TRAJECTORY IS WITHIN FEASIBLE
%LIMITS
Error = -1;
return;

end

