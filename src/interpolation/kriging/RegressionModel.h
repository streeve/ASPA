//
// File:        RegressionModel.h
// Package:     MPTCOUPLER kriging algorithm
// 
// 
// 
// Description: Abstract base class for stochastic regression model.
//
// $Id: RegressionModel.h,v 1.1 2005/08/23 21:12:40 knap2 Exp $
//
// $Log: RegressionModel.h,v $
// Revision 1.1  2005/08/23 21:12:40  knap2
// Initial source.
//
//

#if !defined(included_krigalg_RegressionModel)
#define included_krigalg_RegressionModel

#ifndef included_config
#include "asf_config.h"
#endif // included_config

#ifndef included_krigalg_Dimension
#include <base/Dimension.h>
#endif

#ifndef included_krigalg_Matrix
#include <base/Matrix.h>
#endif

#ifndef included_krigalg_Point
#include <base/Point.h>
#endif

#ifndef included_boost_shared_ptr
#define included_boost_shared_ptr
#include <boost/shared_ptr.hpp>
#endif

namespace MPTCOUPLER {

  //
  // forward declarations
  //
  
  namespace toolbox {
    
    class Database;
    
  }

  namespace krigalg {

  //
  // forward declarations
  //

  class RegressionModel;
  typedef boost::shared_ptr<RegressionModel> RegressionModelPointer;  

  //
  // class definition
  //

  class RegressionModel {

    //
    // methods
    //

  public:
    
    //
    // construction/destruction
    //

    RegressionModel();
    virtual ~RegressionModel() = 0;

    //
    // meta-methods
    //

    virtual Matrix    getValues(const Point & point) const = 0;
    virtual Dimension getDimension(const Point & point) const = 0;
    
    //
    // Database input/output
    //

    virtual std::string getClassName() const = 0;
    virtual void putToDatabase(toolbox::Database & db) const;
    virtual void getFromDatabase(toolbox::Database & db);

  private:
    //
    // copy construction/assignment
    //
    
    RegressionModel(const RegressionModel &);
    const RegressionModel & operator=(const RegressionModel &);

  };

}
}

#endif // included_krigalg_RegressionModel
