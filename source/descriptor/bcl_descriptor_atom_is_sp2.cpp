// (c) Copyright BCL @ Vanderbilt University 2014
// (c) BCL Homepage: http://www.meilerlab.org/bclcommons
// (c) BCL Code Repository: https://github.com/BCLCommons/bcl
// (c)
// (c) The BioChemical Library (BCL) was originally developed by contributing members of the Meiler Lab @ Vanderbilt University.
// (c)
// (c) The BCL is now made available as an open-source software package distributed under the permissive MIT license,
// (c) developed and maintained by the Meiler Lab at Vanderbilt University and contributing members of the BCL Commons.
// (c)
// (c) External code contributions to the BCL are welcome. Please visit the BCL Commons GitHub page for information on how you can contribute.
// (c)
// (c) This file is part of the BCL software suite and is made available under the MIT license.
// (c)

// initialize the static initialization fiasco finder, if macro ENABLE_FIASCO_FINDER is defined
#include "util/bcl_util_static_initialization_fiasco_finder.h"
#include <chemistry/bcl_chemistry_hybrid_orbital_types.h>
BCL_StaticInitializationFiascoFinder

// include header of this class
#include "descriptor/bcl_descriptor_atom_is_sp2.h"

// includes from bcl - sorted alphabetically
#include "chemistry/bcl_chemistry_stereocenters_handler.h"

// external includes - sorted alphabetically

namespace bcl
{
  namespace descriptor
  {
  //////////////////////////////////
  // construction and destruction //
  //////////////////////////////////

    //! @brief virtual copy constructor
    //! @return pointer to new AtomIsSP2
    AtomIsSP2 *AtomIsSP2::Clone() const
    {
      return new AtomIsSP2( *this);
    }

  /////////////////
  // data access //
  /////////////////

    //! @brief get name of the current class
    //! @return name of the class
    const std::string &AtomIsSP2::GetClassIdentifier() const
    {
      return GetStaticClassName( *this);
    }

    //! @brief return the name of the property without any parameters
    //! @return name of the property as string
    const std::string &AtomIsSP2::GetAlias() const
    {
      static const std::string s_name( "Atom_IsSP2");
      return s_name;
    }

  ////////////////
  // operations //
  ////////////////

    //! @brief calculate the descriptors
    //! @param ELEMENT the element of the sequence of interest
    //! @param STORAGE storage for the descriptor
    void AtomIsSP2::Calculate
    (
      const iterate::Generic< const chemistry::AtomConformationalInterface> &ELEMENT,
      linal::VectorReference< float> &STORAGE
    )
    {
      if( ELEMENT->GetAtomType()->GetHybridOrbitalType() == chemistry::GetHybridOrbitalTypes().e_SP2)
      {
        STORAGE( 0) = float( 1.0);
      }
      else if( ELEMENT->GetAtomType()->GetNumberBonds() > size_t( 1))
      {
        STORAGE( 0) = float( -1.0);
      }
    } // Recalculate

  //////////////////////
  // helper functions //
  //////////////////////

    //! @brief return parameters for member data that are set up from the labels
    //! @return parameters for member data that are set up from the labels
    io::Serializer AtomIsSP2::GetSerializer() const
    {
      io::Serializer parameters;
      parameters.SetClassDescription( "1 for sp2, -1 for non-sp2 non-terminal atoms, 0 for everything else");
      return parameters;
    }

  } // namespace descriptor
} // namespace bcl
