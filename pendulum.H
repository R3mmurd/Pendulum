/*
  Simple Pendulum Simulation.

  Author: Alejandro Mujica (aledrums@gmail.com)
*/

# ifndef PENDULUM_H
# define PENDULUM_H

# include <QPoint>
# include <QPainter>

class Pendulum
{
public:
  static constexpr qreal GRAVITY = 10;

  static constexpr qint32 ratio = 15;

private:
   qreal length;

   qreal theta;

   qreal theta_p;

   QPoint position;

   QPoint extreme;

public:
  Pendulum();

  void move(const QPoint & point);

  void integrate(const quint32 & dt);

  void draw(QPainter & painter);
};

# endif // PENDULUM_H
