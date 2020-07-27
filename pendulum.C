/*
  Simple Pendulum Simulation.

  Author: Alejandro Mujica (aledrums@gmail.com)
*/

# include <pendulum.H>

# include <QtMath>

Pendulum::Pendulum()
  : length(200), theta(0.0), theta_p(0.0), position(400, 300)
{
  extreme.setX((qint32) (length * qSin(theta) + position.x()));
  extreme.setY((qint32) (length * qCos(theta) + position.y()));
}

void Pendulum::move(const QPoint & point)
{
  extreme.setX(point.x());
  extreme.setY(point.y());

  length = qSqrt(qPow(position.x() - extreme.x(), 2) +
                       qPow(position.y() - extreme.y(),  2));

  theta = qAsin((qreal) (extreme.x() - position.x()) / ((qreal) length));

  theta_p = 0;

  if (extreme.y() < position.y())
    {
       if (extreme.x() < position.x())
         theta = -M_PI - theta;
       else
         theta = M_PI - theta;
    }
}

void Pendulum::integrate(const quint32 & dt)
{
  qreal delta_t = (qreal) dt / 100;

  theta_p = theta_p - delta_t * (qSin(theta) * GRAVITY / length);
  theta = theta + delta_t * theta_p;
  extreme.setX((quint32) (length * qSin(theta)) + position.x());
  extreme.setY((quint32) (length * qCos(theta)) + position.y());
}

void Pendulum::draw(QPainter & painter)
{
  painter.setPen(Qt::black);
  painter.setBrush(Qt::black);

  painter.drawLine(position.x() - length / 2, position.y(),
                   position.x() + length / 2, position.y());
  painter.drawLine(position, extreme);
  painter.drawEllipse(extreme, ratio, ratio);
}

