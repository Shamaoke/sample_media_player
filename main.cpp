
///
/// ::: Main entrypoint :::
///

#include <QGuiApplication>
#include <QQmlApplicationEngine>

auto main(int argc, char* argv[ ], [[maybe_unused]] char* env[ ]) -> int {

  auto app { QGuiApplication { argc, argv, } };
  auto engine { QQmlApplicationEngine { } };
  // auto window { QUrl { "qrc:/Components/Main.qml" } };
  auto window { QUrl { "qrc:/qt/qml/Components/Main.qml" } };

  engine.load(window);

  auto exit_status { app.exec() };

  return exit_status;
}

