#pragma once

#include <QAbstractItemModel>
#include <deque>
#include <memory>
#include <string>


struct TestModelItem
{
	std::string label;
};

class TestAssetModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	TestAssetModel();
	~TestAssetModel();

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex& child) const override { return {}; }

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override { return 1; }

	void customRemoveRow(int row);
	Q_INVOKABLE void removeFromBegin();
private:
	std::deque<std::shared_ptr<TestModelItem>> m_items;
};
