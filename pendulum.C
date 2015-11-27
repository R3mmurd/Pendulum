/*
  Simple Pendulum Simulation.
  Copyright (C) 2009 by Alejandro J. Mujica

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  Any user request of this software, write to

  Alejandro Mujica

  aledrums@gmail.com
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

