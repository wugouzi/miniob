// #include "sql/operator/pretable_scan_operator.h"
// #include "storage/common/table.h"
// #include "rc.h"

// RC PretableScanOperator::open()
// {
//   return RC::SUCCESS;
// }

// RC PretableScanOperator::next()
// {
//   if (iter_ != table_->end()) {
//     iter_++;
//     return RC::SUCCESS;
//   }
//   return RC::RECORD_EOF;
// }

// RC PretableScanOperator::close()
// {
//   return RC::SUCCESS;
// }

// Tuple * PretableScanOperator::current_tuple()
// {
//   return *iter_;
// }
