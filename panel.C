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

# include <panel.H>

# include <QMouseEvent>

Panel::Panel(QWidget *parent) : QWidget(parent)
{
  setFixedSize(800, 600);

  timer.setInterval(33);

  connect(&timer, SIGNAL(timeout()), this, SLOT(update()));

  timer.start();
  time.start();
}

void Panel::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  painter.fillRect(0, 0, width(), height(), Qt::white);

  pendulum.draw(painter);
}

void Panel::mouseMoveEvent(QMouseEvent * evt)
{
  timer.stop();

  pendulum.move(evt->pos());

  repaint();
}

void Panel::mouseReleaseEvent(QMouseEvent *)
{
  timer.start();
  time.start();
}

void Panel::update()
{
  quint32 dt = time.elapsed();

  pendulum.integrate(dt);

  repaint();

  time.start();
}
