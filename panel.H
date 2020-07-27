/*
  Simple Pendulum Simulation.

  Author: Alejandro Mujica (aledrums@gmail.com)
*/

# ifndef PANEL_H
# define PANEL_H

# include <QWidget>
# include <QTime>
# include <QTimer>

# include <pendulum.H>

class Panel : public QWidget
{
  Q_OBJECT

  Pendulum pendulum;

  QTime time;

  QTimer timer;

protected:
  void paintEvent(QPaintEvent *);

  void mouseMoveEvent(QMouseEvent *);

  void mouseReleaseEvent(QMouseEvent *);

public:
  Panel(QWidget *parent = nullptr);

private slots:
  void update();
};

# endif // PANEL_H
