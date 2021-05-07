#include "testassetmodel.h"

namespace
{
static const int COUNT_ITEMS = 100000;
} // namespace

TestAssetModel::TestAssetModel()
{
	for (size_t i = 0; i < COUNT_ITEMS; i++)
	{
		auto modelItem = std::make_shared<TestModelItem>();
		modelItem->label = "Item #" + std::to_string(i);
		m_items.push_back(modelItem);
	}
}

TestAssetModel::~TestAssetModel() = default;

QVariant TestAssetModel::data(const QModelIndex& index, int role /*= Qt::DisplayRole*/) const
{
	if (!index.isValid() || index.column() != 0 || index.row() >= m_items.size())
	{
		return {};
	}

	const auto& item = m_items[index.row()];

	switch (role)
	{
	case Qt::DisplayRole:
		return QString::fromStdString(item->label);
	}

	return {};
}


QModelIndex TestAssetModel::index(
	int row, int column,
	const QModelIndex& parent /*= QModelIndex()*/) const
{
	if (parent.isValid())
	{
		return {};
	}

	return createIndex(row, column);
}

int TestAssetModel::rowCount(const QModelIndex& parent /*= QModelIndex()*/) const
{
	return parent.isValid() ? 0 : static_cast<int>(m_items.size());
}

void TestAssetModel::removeFromBegin()
{
	int countToRemove = 500;
	countToRemove = std::min(countToRemove, rowCount());
	for (int i = 0; i < countToRemove; i++)
	{
		customRemoveRow(0);
	}
}

void TestAssetModel::customRemoveRow(int row)
{
	beginRemoveRows(QModelIndex(), row, row);

	m_items.erase(m_items.begin() + row);

	endRemoveRows();
}
