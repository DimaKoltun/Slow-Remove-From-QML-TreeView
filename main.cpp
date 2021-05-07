#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "testassetmodel.h"
#include <QQuickView>
#include <QQmlContext>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	TestAssetModel assetModel;

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty(QStringLiteral("assetModel"), &assetModel);
	engine.load(QUrl(QLatin1String("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
	   return -1;

	return app.exec();
}
