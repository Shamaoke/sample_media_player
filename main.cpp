
///
/// ::: Main entrypoint :::
///

#include <QGuiApplication>
#include <QQmlApplicationEngine>

auto main(int argc, char* argv[ ], [[maybe_unused]] char* env[ ]) -> int {

  auto app { QGuiApplication { argc, argv, } };
  auto engine { QQmlApplicationEngine { } };
  auto window { QUrl { "qrc:/Components/Main.qml" } };

  engine.addImportPath("qrc:/");

  engine.load(window);

  auto notify_quit { [ ]( ) { qInfo() << "Exiting from the Sample media player"; } };

  QObject::connect(&app, &QCoreApplication::aboutToQuit, notify_quit);

  auto exit_status { app.exec() };

  return exit_status;
}

