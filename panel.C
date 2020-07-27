/*
  Simple Pendulum Simulation.

  Author: Alejandro Mujica (aledrums@gmail.com)
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
