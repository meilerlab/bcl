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

#ifndef BCL_CHEMISTRY_FRAGMENT_HALOGENATE_H_
#define BCL_CHEMISTRY_FRAGMENT_HALOGENATE_H_

// include the namespace header
#include "bcl_chemistry.h"
#include "descriptor/bcl_descriptor.fwd.hh"

// include other forward headers - sorted alphabetically
#include "find/bcl_find.fwd.hh"

// includes from bcl - sorted alphabetically
#include "bcl_chemistry_atom_conformational_interface.h"
#include "bcl_chemistry_collector_valence.h"
#include "bcl_chemistry_fragment_complete.h"
#include "bcl_chemistry_fragment_constitution_shared.h"
#include "bcl_chemistry_fragment_ensemble.h"
#include "bcl_chemistry_fragment_mutate_interface.h"
#include "descriptor/bcl_descriptor_base.h"
#include "find/bcl_find_pick_interface.h"
#include "math/bcl_math_mutate_interface.h"
#include "math/bcl_math_mutate_result.h"
#include "util/bcl_util_function_interface.h"
#include "util/bcl_util_sh_ptr.h"
#include "util/bcl_util_si_ptr_list.h"
// external includes - sorted alphabetically

namespace bcl
{
  namespace chemistry
  {

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //!
    //! @class FragmentHalogenate
    //! @brief Used to add halogens to ring fragments.
    //!
    //! @see @link example_chemistry_fragment_halogenate.cpp @endlink
    //! @author brownbp1
    //! @date Sep 12, 2019
    //!
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class BCL_API FragmentHalogenate :
      public FragmentMutateInterface
    {

    /////////////
    // friends //
    /////////////

    private:

    //////////
    // data //
    //////////

      //! halogens that are allowed
      storage::Vector< AtomType> m_AllowedHalogens;
      std::string m_AllowedHalogensString;

      //! enables removal of halogens
      bool m_Reversible;

      //! restrict reversibility to allowed halogens
      bool m_RestrictReversibility;

      //! disable aromatic ring requirement
      bool m_DisableAromaticRingReq;

    public:

    //////////
    // data //
    //////////

      //! single instance of that class
      static const util::SiPtr< const util::ObjectInterface> s_Instance;

    //////////////////////////////////
    // construction and destruction //
    //////////////////////////////////

      //! @brief default constructor
      FragmentHalogenate();

      //! @brief druglikeness constructor
      //! @param DRUG_LIKENESS_TYPE type of druglikeness filter to apply during clean
      FragmentHalogenate
      (
        const std::string &DRUG_LIKENESS_TYPE,
        const bool &CORINA_CONFS
      );

      //! @brief full constructor
      //! @param DRUG_LIKENESS_TYPE type of druglikeness filter to apply during clean
      //! @param SCAFFOLD_FRAGMENT fragment to which the new mutated molecule will be aligned based on substructure
      //! @param MUTABLE_FRAGMENTS non-mutable component of the current molecule
      //! @param MUTABLE_ATOM_INDICES indices of atoms that can be mutated
      FragmentHalogenate
      (
        const std::string &DRUG_LIKENESS_TYPE,
        const FragmentComplete &SCAFFOLD_FRAGMENT,
        const FragmentEnsemble &MUTABLE_FRAGMENTS,
        const storage::Vector< size_t> &MUTABLE_ATOM_INDICES,
        const bool &CORINA_CONFS
      );

      //! @brief local mutate pose-sensitive constructor
      //! @param DRUG_LIKENESS_TYPE type of druglikeness filter to apply during clean
      //! @param SCAFFOLD_FRAGMENT fragment to which the new mutated molecule will be aligned based on substructure
      //! @param MUTABLE_FRAGMENTS non-mutable component of the current molecule
      //! @param MUTABLE_ATOM_INDICES indices of atoms that can be mutated
      //! @param MDL property label containing path to protein binding pocket PDB file
      //! @param PROPERTY_SCORER property that will be used to score interactions with protein pocket
      //! @param RESOLVE_CLASHES if true, resolve clashes with specified protein pocket after mutatation
      //! @param BFACTORS vector of values indicating per-residue flexibility (higher values are more flexible)
      FragmentHalogenate
      (
        const std::string &DRUG_LIKENESS_TYPE,
        const FragmentComplete &SCAFFOLD_FRAGMENT,
        const FragmentEnsemble &MUTABLE_FRAGMENTS,
        const storage::Vector< size_t> &MUTABLE_ATOM_INDICES,
        const std::string &MDL,
        const descriptor::CheminfoProperty &PROPERTY_SCORER,
        const bool &RESOLVE_CLASHES,
        const storage::Vector< float> &BFACTORS,
        const bool &CORINA_CONFS
      );

      //! @brief local clash resolver constructor
      //! @param DRUG_LIKENESS_TYPE type of druglikeness filter to apply during clean
      //! @param SCAFFOLD_FRAGMENT fragment to which the new mutated molecule will be aligned based on substructure
      //! @param MUTABLE_FRAGMENTS non-mutable component of the current molecule
      //! @param MUTABLE_ATOM_INDICES indices of atoms that can be mutated
      //! @param MDL property label containing path to protein binding pocket PDB file
      //! @param RESOLVE_CLASHES if true, resolve clashes with specified protein pocket after mutatation
      //! @param BFACTORS vector of values indicating per-residue flexibility (higher values are more flexible)
      FragmentHalogenate
      (
        const std::string &DRUG_LIKENESS_TYPE,
        const FragmentComplete &SCAFFOLD_FRAGMENT,
        const FragmentEnsemble &MUTABLE_FRAGMENTS,
        const storage::Vector< size_t> &MUTABLE_ATOM_INDICES,
        const std::string &MDL,
        const bool &RESOLVE_CLASHES,
        const storage::Vector< float> &BFACTORS,
        const bool &CORINA_CONFS
      );

      //! @brief clone constructor
      FragmentHalogenate *Clone() const;

    /////////////////
    // data access //
    /////////////////

      //! @brief returns class name
      //! @return the class name as const ref std::string
      const std::string &GetClassIdentifier() const;

      //! @brief returns the name used for this class in an object data label
      //! @return the name used for this class in an object data label
      const std::string &GetAlias() const;

      //! @brief returns the mutable atoms
      //! @return the mutable atoms
      const storage::Vector< size_t> &GetMutableAtomIndices() const;

    ///////////////
    // operators //
    ///////////////

      //! @brief virtual operator taking an SmallMolecule and returning a grown SmallMolecule
      //! @param FRAGMENT small molecule of interest
      //! @return Constitution after the mutate
      math::MutateResult< FragmentComplete> operator()( const FragmentComplete &FRAGMENT) const;

    ////////////////
    // operations //
    ////////////////

      //! @brief set the fragment mutable atom indices
      void SetAllowedHalogens( const storage::Vector< AtomType> &ALLOWED_HALOGENS);

      //! @brief set reversibility
      void SetReversibility( const bool REVERSIBLE);

    //////////////////////
    // helper functions //
    //////////////////////

    protected:

      //! @brief return parameters for member data that are set up from the labels
      //! @return parameters for member data that are set up from the labels
      io::Serializer GetSerializer() const;

      //! @brief Set the members of this property from the given LABEL
      //! @param LABEL the label to parse
      //! @param ERROR_STREAM the stream to write errors to
      bool ReadInitializerSuccessHook( const util::ObjectDataLabel &LABEL, std::ostream &ERROR_STREAM);

    }; // class FragmentHalogenate

  } // namespace chemistry
} // namespace bcl

#endif //BCL_CHEMISTRY_FRAGMENT_HALOGENATE_H_
