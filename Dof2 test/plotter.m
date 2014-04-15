figure
subplot(1,2,1)
hold all;
title('First joint');
plot(qa1.Time,qa1.Data,'LineWidth',2);
plot(q1.Time,q1.Data,'LineWidth',2);
xlabel('t [s]');
ylabel('q [rad]');
legend('Reference','Output');
hold off

subplot(1,2,2)
hold all;
title('Second joint');
plot(qa2.Time,qa2.Data,'LineWidth',2);
plot(q2.Time,q2.Data,'LineWidth',2);
xlabel('t [s]');
ylabel('q [rad]');
legend('Reference','Output');
hold off