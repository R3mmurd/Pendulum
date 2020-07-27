/*
  Simple Pendulum Simulation.

  aledrums@gmail.com
*/

# include <QApplication>
# include <panel.H>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Panel * p = new Panel;

  p->show();

  return app.exec();
}

